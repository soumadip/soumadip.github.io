function parseToPics(text){
  if (window.DOMParser){
    var parser = new DOMParser();
    var xmlDoc = parser.parseFromString(text, "text/xml");
  }
  else{
    var xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
    xmlDoc.async = false;
    xmlDoc.loadXML(text);
  }
  var basedir = xmlDoc.getElementsByTagName("basedir")[0].childNodes[0].nodeValue.trim();
  var entries = xmlDoc.getElementsByTagName("entry");
  //console.log(entries);
  // var txt = "<h4>" + heading + "</h4>";
  var txt = "";
  var temp = "<a onclick=\"return popup('{image}', '{description}')\" target=_blank><div class='cell' style='width:{width}px; height: {height}px; background-image: url({thumb}'></div></a>";
  for (e = 0; e < entries.length; e++) {
    var entry = entries[e];
    var thumb = entry.children[0].childNodes[0].nodeValue.trim();
    var h = entry.children[1].childNodes[0].nodeValue.trim();
    var w = entry.children[2].childNodes[0].nodeValue.trim();
    var description = entry.children[3].childNodes[0].nodeValue.trim();
    var image = entry.children[4].childNodes[0].nodeValue.trim();
    txt += temp .replace("{image}", basedir+image)
                .replace(/\{height\}/g, h)
                .replace(/\{width\}/g, w)
                .replace("{thumb}", basedir+thumb)
                .replace("{description}", description);
    }
  return txt;
}

function loadGallary(id, page_url){
  var xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
  xhr.open('get', page_url, true);
  xhr.onreadystatechange = function() {
      if (xhr.readyState == 4 && xhr.status == 200) {
      var pics = parseToPics(xhr.responseText);
      document.getElementById(id).innerHTML = pics;
    }
  }
  xhr.send();
}

function initGallary(){
  loadGallary("freewall", "data/asphic.xml");

  var wall = new Freewall("#freewall");
  wall.reset({
    selector: '.cell',
    animate: true,
    cellW: 20,
    cellH: 200,
    onResize: function() {
      wall.fitWidth();
    }
  });
  wall.fitWidth();
  // for scroll bar appear;
  $(window).trigger("resize");

  window.onclick = function(event) {
  var modal = document.getElementById("viewer");
  if (event.target == modal) {
      modal.style.display = "none";
    }
  }
}

// When the user clicks on the button, open the popup 
function popup(img_url, description) {
  var modal = document.getElementById("viewer");
  var container = document.getElementById("container");
  var captionText = document.getElementById("caption");

  modal.style.display = "block";
 
  container.src = img_url;
  captionText.innerHTML = description;
}

