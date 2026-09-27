let currentTab = 0;
const tabCount = 2;
let carouselTimer;

function switchTab(index, userClicked = false) {
  document
    .querySelectorAll(".tab-content")
    .forEach((el) => el.classList.remove("active"));
  document
    .querySelectorAll(".tab-btn")
    .forEach((el) => el.classList.remove("active"));

  document.getElementById("tab-" + index).classList.add("active");
  document.querySelectorAll(".tab-btn")[index].classList.add("active");

  currentTab = index;
  if (userClicked) clearInterval(carouselTimer);
}

document.addEventListener("DOMContentLoaded", () => {
  // Only run the timer if we are on a page with tabs
  if (document.getElementById("tab-0")) {
    carouselTimer = setInterval(() => {
      let nextTab = (currentTab + 1) % tabCount;
      switchTab(nextTab, false);
    }, 6000);
  }
});

// Course Material Tabs Logic
function switchMaterialTab(index) {
  // Hide all material tab contents and remove active state from all material buttons
  document
    .querySelectorAll(".material-tab-content")
    .forEach((el) => el.classList.remove("active"));
  document
    .querySelectorAll(".material-tab-btn")
    .forEach((el) => el.classList.remove("active"));

  // Show the selected tab and highlight its button
  document.getElementById("mat-tab-" + index).classList.add("active");
  document.querySelectorAll(".material-tab-btn")[index].classList.add("active");
}

// --- Client-Side Search Engine ---
document.addEventListener("DOMContentLoaded", () => {
  const searchInput = document.getElementById("search-input");
  const searchResults = document.getElementById("search-results");

  if (!searchInput || !searchResults) return;

  let searchIndex = null;
  let isFetching = false;

  // Async fetch with a lock to prevent duplicate network requests
  async function getSearchIndex() {
    if (searchIndex) return searchIndex;
    if (isFetching) {
      // Wait for the active fetch to complete
      while (isFetching) await new Promise((r) => setTimeout(r, 50));
      return searchIndex;
    }

    isFetching = true;
    try {
      // Dynamically calculate the base URL to support subpath hosting
      // const baseUrl = window.location.origin + window.location.pathname.replace(/\/$/, "");
      const indexUrl = searchResults.dataset.indexUrl || "/index.json";
      const response = await fetch(indexUrl);
      if (!response.ok)
        throw new Error(`Search index failed: ${response.status}`);
      searchIndex = await response.json();
    } catch (error) {
      console.error("Failed to load search index:", error);
      searchIndex = [];
    } finally {
      isFetching = false;
    }
    return searchIndex;
  }

  searchInput.addEventListener("input", async (e) => {
    const rawQuery = e.target.value.toLowerCase().trim();
    searchResults.innerHTML = ""; // Clear previous results

    if (rawQuery.length < 2) {
      searchResults.classList.remove("active");
      return;
    }

    // Split the query into an array of words
    const searchWords = rawQuery.split(/\s+/).filter(word => word.length > 0);

    // Await the index (will resolve instantly if already cached)
    const data = await getSearchIndex();

    // Fuzzy matching: Return true only if EVERY word is found in the title or content
    const filtered = data.filter((item) => {
      const title = item.title ? item.title.toLowerCase() : "";
      const content = item.content ? item.content.toLowerCase() : "";

      return searchWords.every(word => title.includes(word) || content.includes(word));
    });

    if (filtered.length === 0) {
      const noRes = document.createElement("div");
      noRes.textContent = "No results found.";
      noRes.className = "search-item"; // Style this in CSS
      searchResults.appendChild(noRes);
      searchResults.classList.add("active");
      return;
    }

    filtered.slice(0, 8).forEach((item) => {
      // Create DOM elements safely to prevent XSS
      const link = document.createElement("a");
      link.href = item.permalink;
      link.className = "search-item";

      const title = document.createElement("span");
      title.className = "search-item-title";
      title.textContent = item.title; // Safe text injection

      link.appendChild(title);
      searchResults.appendChild(link);
    });

    searchResults.classList.add("active");
  });

});
