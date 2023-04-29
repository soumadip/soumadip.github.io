// <script type="text/javascript">
if(typeof(String.prototype.trim) === "undefined")
{
	String.prototype.trim = function() 
	{
		return String(this).replace(/^\s+|\s+$/g, '');
	};
}

function parse_Idea_data(id, text){
	if (window.DOMParser){
		var parser = new DOMParser();
		var xmlDoc = parser.parseFromString(text, "text/xml");
	}
	else{
		var xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
		xmlDoc.async = false;
		xmlDoc.loadXML(text);
	}
	var heading = xmlDoc.getElementsByTagName("heading")[0].children[0].childNodes[0].nodeValue.trim();
	var entries = xmlDoc.getElementsByTagName("entry");
	//console.log(entries);
	var txt = "<h4>" + heading + "</h4>";
	for (e = 0; e < entries.length; e++) {
		var entry = entries[e];
		var period = '(' + (e+1) + ') ' + entry.children[0].childNodes[0].nodeValue.trim();
		var head = entry.children[1].childNodes[0].nodeValue.trim();
		var details = entry.children[2].childNodes[0].nodeValue.trim().split("\n");
		var slines = '';
		for (i = 0; i < details.length; i++){
			slines += details[i].trim() + ' ';
		}
		txt += "<div class='time'><h5>" + period 
			+ "</h5><p><b>" + head + "</b> <br />"
			+ "<small>" + slines + "</small></p></div>";
	}
	document.getElementById(id).innerHTML = txt;
}

function parse_Ta_data(id, text){
	if (window.DOMParser){
		var parser = new DOMParser();
		var xmlDoc = parser.parseFromString(text, "text/xml");
	}
	else{
		var xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
		xmlDoc.async = false;
		xmlDoc.loadXML(text);
	}
	var heading = xmlDoc.getElementsByTagName("heading")[0].children[0].childNodes[0].nodeValue.trim();
	var entries = xmlDoc.getElementsByTagName("entry");
	//console.log(entries);
	var txt = "<h4>" + heading + "</h4>";
	for (e = 0; e < entries.length; e++) {
		var entry = entries[e];
		var period = entry.children[0].childNodes[0].nodeValue.trim();
		var courseNo = entry.children[1].childNodes[0].nodeValue.trim();
		var courseName = entry.children[2].childNodes[0].nodeValue.trim();
		var faculty = entry.children[3].childNodes[0].nodeValue.trim();

		txt += "<div class='time'><h5>" + period + "</h5>"
			+ "<p><b>" + courseName + "</b> <br />" 
			+ "<i>Course No</i> : " + courseNo + "<br />" 
			+ "<i>Faculty</i> : " + faculty + "<br /></p></div>";
	}
	document.getElementById(id).innerHTML = txt;
}

function parse_Ca_data(id, text){
	if (window.DOMParser){
		var parser = new DOMParser();
		var xmlDoc = parser.parseFromString(text, "text/xml");
	}
	else{
		var xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
		xmlDoc.async = false;
		xmlDoc.loadXML(text);
	}
	var heading = xmlDoc.getElementsByTagName("heading")[0].children[0].childNodes[0].nodeValue.trim();
	var entries = xmlDoc.getElementsByTagName("entry");
	//console.log(entries);
	var txt = "<h4>" + heading + "</h4>";
	for (e = 0; e < entries.length; e++) {
		var entry = entries[e];
		var period = entry.children[0].childNodes[0].nodeValue.trim();
		var head = entry.children[1].childNodes[0].nodeValue.trim();
		var details = entry.children[2].childNodes[0].nodeValue.trim().split("\n");
		var fline = details[0].trim();
		var slines = '';
		for (i = 1; i < details.length; i++){
			slines += details[i].trim() + '<br />';
		}
		txt += "<div class='time'><h5>" + period 
			+ "</h5><p><b>" + head + "</b> <br />" + fline 
			+ "<br /><small>" + slines + "</small></p></div>";
	}
	document.getElementById(id).innerHTML = txt;
}

function loadCareer(id, page_url){
	var ca_page_url = 'pages/data/ca_timeline.xml'
	var ta_page_url = 'pages/data/ta_timeline.xml'
	var ca_id = 'ca_timeline'
	var ta_id = 'ta_timeline'

	var xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	var ca_xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	var ta_xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');

	xhr.open('get', page_url, true);


	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && xhr.status == 200) {
			document.getElementById(id).innerHTML = xhr.responseText;
			ca_xhr.open('get', ca_page_url, true);
			ta_xhr.open('get', ta_page_url, true);
			ca_xhr.send();
			ta_xhr.send();
		}
	}
	ca_xhr.onreadystatechange = function() {
		if (ca_xhr.readyState == 4 && ca_xhr.status == 200) {
			//document.getElementById(ca_id).innerHTML = ca_xhr.responseText;
			parse_Ca_data(ca_id, ca_xhr.responseText);
		}
	}
	ta_xhr.onreadystatechange = function() {
		if (ta_xhr.readyState == 4 && ta_xhr.status == 200) {
			//document.getElementById(ta_id).innerHTML = ta_xhr.responseText;
			parse_Ta_data(ta_id, ta_xhr.responseText);
		}
	}
	xhr.send()
}

function loadIdeas(id, page_url){
	var idea_page_url = 'pages/data/ideas_timeline.xml'
	var idea_id = 'idea_timeline'

	var xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	var idea_xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');

	xhr.open('get', page_url, true);


	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && xhr.status == 200) {
			document.getElementById(id).innerHTML = xhr.responseText;
			idea_xhr.open('get', idea_page_url, true);
			idea_xhr.send();
		}
	}
	idea_xhr.onreadystatechange = function() {
		if (idea_xhr.readyState == 4 && idea_xhr.status == 200) {
			//document.getElementById(ca_id).innerHTML = ca_xhr.responseText;
			parse_Idea_data(idea_id, idea_xhr.responseText);
		}
	}
	xhr.send()
}

function parse_CJO_data(id, text, context){
	if (window.DOMParser){
		var parser = new DOMParser();
		var xmlDoc = parser.parseFromString(text, "text/xml");
	}
	else{
		var xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
		xmlDoc.async = false;
		xmlDoc.loadXML(text);
	}
	var heading = xmlDoc.getElementsByTagName("heading")[0].children[0].childNodes[0].nodeValue.trim();
	var entries = xmlDoc.getElementsByTagName("entry");
	//console.log(entries);
	var txt = "<h4>" + heading + "</h4>";
	var count = entries.length;
	for (e = 0; e < count; e++) {
		var entry = entries[e];
		if (context == "conferences")
		{
			var index = "<tr><th>[" + (count - e) +"]</th><th>" + entry.children[0].childNodes[0].nodeValue.trim() + "</th></tr>";
			//var paper = "<tr><td>Title</td><td>" + entry.children[0].childNodes[0].nodeValue.trim() + "</td></tr>";
			var authors = "<tr><td>Authors</td><td>" + entry.children[1].childNodes[0].nodeValue.trim() + "</td></tr>";
			var conference = "<tr><td>Conference</td><td>" + entry.children[2].childNodes[0].nodeValue.trim() + "</td></tr>";
			var year = "<tr><td>Year</td><td>" + entry.children[3].childNodes[0].nodeValue.trim() + "</td></tr>";
			var venue = "<tr><td>Venue</td><td>" + entry.children[4].childNodes[0].nodeValue.trim() + "</td></tr>";
			var keywords = "<tr><td>Keywords</td><td>" + entry.children[5].childNodes[0].nodeValue.trim() + "</td></tr>";
			var bibtex = "<tr><td><a href=pages/data/bib/" + entry.children[6].childNodes[0].nodeValue.trim() + ".bib target=\"_blank\">Bibtex</a></td></tr>"
			
			txt += "<div class='timeCJO'><table>" + [index, authors, conference, year, venue, keywords, bibtex].join("") + "</table></div>";
		}
		if (context == "journals")
		{
			var index = "<tr><th>[" + (count - e) +"]</th><th>" + entry.children[0].childNodes[0].nodeValue.trim() + "</th></tr>";
			//var paper = "<tr><td>Title</td><td>" + entry.children[0].childNodes[0].nodeValue.trim() + "</td></tr>";
			var authors = "<tr><td>Authors</td><td>" + entry.children[1].childNodes[0].nodeValue.trim() + "</td></tr>";
			var journal = "<tr><td>Journal</td><td>" + entry.children[2].childNodes[0].nodeValue.trim() + "</td></tr>";
			var year = "<tr><td>Year</td><td>" + entry.children[3].childNodes[0].nodeValue.trim() + "</td></tr>";
			var vol = "<tr><td>Volume</td><td>" + entry.children[4].childNodes[0].nodeValue.trim() + "</td></tr>";
			var keywords = "<tr><td>Keywords</td><td>" + entry.children[5].childNodes[0].nodeValue.trim() + "</td></tr>";
			var bibtex = "<tr><td><a href=pages/data/bib/" + entry.children[6].childNodes[0].nodeValue.trim() + ".bib target=\"_blank\">Bibtex</a></td></tr>"
			
			txt += "<div class='timeCJO'><table>" + [index, authors, journal, year, vol, keywords, bibtex].join("") + "</table></div>";
		}
		if (context == "others")
		{
			var index = "<tr><th>[" + (count - e) +"]</th><th>" + entry.children[0].childNodes[0].nodeValue.trim() + "</th></tr>";
			//var paper = "<tr><td>Title</td><td>" + entry.children[0].childNodes[0].nodeValue.trim() + "</td></tr>";
			var authors = "<tr><td>Authors</td><td>" + entry.children[1].childNodes[0].nodeValue.trim() + "</td></tr>";
			var conference = "<tr><td>Conference</td><td>" + entry.children[2].childNodes[0].nodeValue.trim() + "</td></tr>";
			var year = "<tr><td>Year</td><td>" + entry.children[3].childNodes[0].nodeValue.trim() + "</td></tr>";
			var venue = "<tr><td>Venue</td><td>" + entry.children[4].childNodes[0].nodeValue.trim() + "</td></tr>";
			var keywords = "<tr><td>Keywords</td><td>" + entry.children[5].childNodes[0].nodeValue.trim() + "</td></tr>";
			var bibtex = "<tr><td><a href=pages/data/bib/" + entry.children[6].childNodes[0].nodeValue.trim() + ".bib target=\"_blank\">Bibtex</a></td></tr>"
			
			txt += "<div class='timeCJO'><table>" + [index, authors, conference, year, venue, keywords, bibtex].join("") + "</table></div>";
		}
	}
	document.getElementById(id).innerHTML = txt;
}

function loadPublications(id, page_url){
	var c_page_url = 'pages/data/conferences_timeline.xml'
	var j_page_url = 'pages/data/journals_timeline.xml'
	var o_page_url = 'pages/data/others_timeline.xml'
	var c_id = 'c_timeline'
	var j_id = 'j_timeline'
	var o_id = 'o_timeline'

	var xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	var c_xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	var j_xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	var o_xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');

	xhr.open('get', page_url, true);


	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && xhr.status == 200) {
			document.getElementById(id).innerHTML = xhr.responseText;
			c_xhr.open('get', c_page_url, true);
			j_xhr.open('get', j_page_url, true);
			o_xhr.open('get', o_page_url, true);
			c_xhr.send();
			j_xhr.send();
			o_xhr.send();
		}
	}
	c_xhr.onreadystatechange = function() {
		if (c_xhr.readyState == 4 && c_xhr.status == 200) {
			parse_CJO_data(c_id, c_xhr.responseText, "conferences");
		}
	}
	j_xhr.onreadystatechange = function() {
		if (j_xhr.readyState == 4 && j_xhr.status == 200) {
			parse_CJO_data(j_id, j_xhr.responseText, "journals");
		}
	}
	o_xhr.onreadystatechange = function() {
		if (o_xhr.readyState == 4 && o_xhr.status == 200) {
			parse_CJO_data(o_id, o_xhr.responseText, "others");
		}
	}
	xhr.send()
}

function loadPage(id, page_url){
	var xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	xhr.open('get', page_url, true);
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && xhr.status == 200) {
			document.getElementById(id).innerHTML = xhr.responseText;
		}
	}
	xhr.send();
}

function loadArticle(id, page_url){
	var xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	xhr.open('get', page_url, true);
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && xhr.status == 200) {
			document.getElementById(id).innerHTML = xhr.responseText;
		}
	}
	xhr.send();
}

function parseToLinks(text){
	if (window.DOMParser){
		var parser = new DOMParser();
		var xmlDoc = parser.parseFromString(text, "text/xml");
	}
	else{
		var xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
		xmlDoc.async = false;
		xmlDoc.loadXML(text);
	}
	var heading = xmlDoc.getElementsByTagName("heading")[0].children[0].childNodes[0].nodeValue.trim();
	var entries = xmlDoc.getElementsByTagName("entry");
	//console.log(entries);
	var txt = "<h4>" + heading + "</h4>";
	for (e = 0; e < entries.length; e++) {
		var entry = entries[e];
		var title = entry.children[0].childNodes[0].nodeValue.trim();
		var link = entry.children[1].childNodes[0].nodeValue.trim();
		txt += "<div class='links' ><a href=" + link 
			+ " /target='_blank'>Link</a> to " + title 
			+ ".</div><br />";
	}
	return txt;
}

function loadLinks(id, page_url){
	var xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	xhr.open('get', page_url, true);
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && xhr.status == 200) {
			var links = parseToLinks(xhr.responseText);
			document.getElementById(id).innerHTML = links;
		}
	}
	xhr.send();
}

function loadInformation(id, page_url){
	var xhr = typeof XMLHttpRequest != 'undefined' ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
	xhr.open('get', page_url, true);
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && xhr.status == 200) {
			document.getElementById(id).innerHTML = xhr.responseText;
			loadLinks('links_research', 'pages/data/links_research.xml');
			loadLinks('links_interesting', 'pages/data/links_interesting.xml');
		}
	}
	xhr.send();
}

function removeCover() {
	document.getElementById("olay").style.display = "none";
	document.getElementById("container").classList.remove("blur");
}

function init(){
	loadPage("title", "pages/layout/title.html");
	loadPage("bottom", "pages/layout/navbar.html");
	loadArticle("middle", "pages/abstract.html");
	loadPage("cover", "pages/layout/cover.html");
}
// </script>
