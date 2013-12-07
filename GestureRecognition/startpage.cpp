#include <iostream>
#include "startpage.h"

using namespace std;

int startpage()
{
	cout << "Content-Type: text/html\n\n";
	cout << "<head>"
		//used libraries
		<< "<link rel=\"stylesheet\" href=\"../websiteGI/libraries/leaflet-0.6.4/leaflet.css\"></link>"
		<< "<script src=\"../websiteGI/libraries/leaflet-0.6.4/leaflet.js\"></script>"
		<< "<script src=\"../websiteGI/libraries/jQuery.js\"></script>"
		<< "<script src=\"http://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js\">"
		<< "</script>"
		//<!-- created style sheets and scripts-->
		<< "<link rel = \"stylesheet\" href = \"../websiteGI/startpage.css\"></link>"
		<< "<script src=\"../websiteGI/startpageFunctions.js\"></script>"
		<< "</head>"


		<< "<body>"
		<< "<div id=\"map\"></div>"
		<< "<div align=\"center\"> "
		<< "<button type=\"button\" onclick=\"mapup()\"style=\"align:left;position:absolute;top:60 %;left:10 %;\">up</button>"
		<< "<input type='button' id='Btn1' value='Add Point' onclick='addPoint()' class='btnStyle span3' style=\"align:center;position:absolute;top:63 %;left:49 %; \"/>"
		<< "</div>"
		<< "<div align=\"center\">"
		<< "<button type=\"button\" onclick=\"mapleft()\"style=\"align:left; position:absolute; top:63 %;left:5 %; \">left</button> "
		<< "<button type=\"button\"onclick=\"mapright()\"style=\"align:left; position:absolute; top:63 %;left:15 %; \">right</button> "
		<< "</div>"
		<< "<div align=\"center\">"
		<< "<button type=\"button\"onclick=\"mapdown()\"style=\"align:center; position:absolute; top:68 % ; left:10 % ; \">down</button></div> "
		<< "<div align=\"center\">"
		//!--<input type='button' id='Btn2' value='Save' onclick='save()' class='btnStyle span3'style="align:center; position:absolute;top:68%;left:50%;" />-->
		<< "</div >"
		<< "</div >"
		<< "<script>"
		//<< "callPoints();"
		/**
		The map is created and some layers are added to the map.
		reference: http://leafletjs.com/examples/quick-start-example.html
		http://leafletjs.com/reference.html#tilelayer-wms
		http://leafletjs.com/examples/layers-control.html
		*/
		//create map
		<< "var map = L.map('map').setView([51.9604,7.6197], 14);"
		//OSM maps one as overlay and one base layer 
		<< "var layerOSM=L.tileLayer('http://a.tile.openstreetmap.org/{z}/{x}/{y}.png', {"
		<< "attribution: '&copy<a href=\"www.openstretmap.org/copyright \">OpenStreetMap</a> contributors',"
		<< "});"

		<< "var layerOSMtransparent=L.tileLayer('http://a.tile.openstreetmap.org/{z}/{x}/{y}.png', {"
		<< "attribution: '&copy<a href=\"www.openstretmap.or /copyright \">OpenStreetMap</a> contributors',"
		<< "opacity:0.5,"
		<< "format: 'image/png',"
		<< "});"

		//Layers of Geobasis NRW: http://www.bezreg-koeln.nrw.de/brk_internet/organisation/abteilung07/produkte/nrwatlas/index.html 
		//                          (website which provides different Web Map Service (WMS)-URLs)
		<< "var layerDTK10_pan=L.tileLayer.wms('http://www.wms.nrw.de/geobasis/wms_nw_dtk10', {"
		<< "attribution: '| &copy Geobasis NRW 2013',"
		<< "layers: 'NW_DTK10_pan',"
		<< "format: 'image/png',"
		<< "transparent: true,"
		<< "opacity:0.4"
		<< "});"

		<< "var layerDTK10=L.tileLayer.wms('http://www.wms.nrw.de/geobasis/wms_nw_dtk10', {"
		<< "attribution: '| &copy Geobasis NRW 2013',"
		<< "layers: 'nw_dtk10_pan,nw_dtk10_res,NW_DTK10_col,WMS_NW_DTK10',"
		<< "format: 'image/png',"
		<< "transparent: true,"
		<< "});"


		//layer of the different districts
		<< "var layerDVG=L.tileLayer.wms('http://www.wms.nrw.de/geobasis/wms_nw_dvg', {"
		<< "attribution: '| &copy Geobasis NRW 2013',"
		<< "layers: 'WMS_NW_DVG',"
		<< "format: 'image/png',"
		<< "transparent: true,"
		<< "opacity:0.5"
		<< "});"

		<< "var layerDGK5=L.tileLayer.wms('http://www.wms.nrw.de/geobasis/wms_nw_dgk5', {"
		<< "attribution: '| &copy Geobasis NRW 2013',"
		<< "layers: 'WMS_NW_DGK5',"
		<< "format: 'image/png',"
		<< "transparent: true,"
		<< "opacity:0.5"
		<< "});"

		//Orthophoto layer
		<< "var layerOrtho = L.tileLayer.wms('http://www.wms.nrw.de/geobasis/wms_nw_dop40', {"
		<< "layers: 'WMS_NW_DOP40',"
		<< "format: 'image/png',"
		<< "version:'1.3.0',"
		<< "attribution: '| &copy Geobasis NRW 2013'"
		<< "});"

		//The map which is visualized when you get on the website.
		<< "layerOSM.addTo(map);"

		//Map control: Layer switcher
		<< "var baseMaps={ \"OSM\": layerOSM,"
		<< "\"arial view\": layerOrtho,"
		<< "\"DTK10\":layerDTK10};"
		<< "var overlapMaps={\"OSM\":layerOSMtransparent,"
		<< "\"DVG\":layerDVG,"
		<< "\"DTK10_pan\":layerDTK10_pan,"
		<< "\"DGK5\":layerDGK5};"
		<< "var control=L.control.layers(baseMaps,overlapMaps,{position:'bottomleft'}).addTo(map);"

		/**
		The sidebar is created. The function onAdd() creates a html object
		for the sidebar and specifies the id of the html element.
		Moreover some attributes for design depending on other objects are defined.
		The listeners are added.
		*/

		<< "var sidebar=L.control();"
		<< "sidebar.onAdd=function(map){"
		<< " this._div = L.DomUtil.create('div', 'sidebar');"
		<< " this._div.id=\"sideBar\";"
		<< " return this._div;};"
		<< "sidebar.addTo(map);"

		<< "var heightSidebar=map.getSize().y-(parseInt($(\".leaflet - control - attribution\").height()));"
		<< "$(\"#sideBar\").css(\"height\",heightSidebar);"
		<< "$(\"#sideBar\").css(\"width\",map.getSize().x/4);"
		<< "$(\"#sideBar\").mouseenter(mouseEnterSidebar);"
		<< "$(\"#sideBar\").mouseleave(mouseLeaveSidebar);"

		/**
		The left border of the sidebar is created.
		Moreover some attributes for design depending on other objects are defined
		and listeners are added.
		*/

		<< "$(\"#sideBar\").append(\"<div id = 'sidebarBorder'class = 'SidebarBorder' style = 'height:\"+heightSidebar+\"' >> ></div>\");"
		<< "$(\"#sidebarBorder\").css(\"width\",map.getSize().x/40);"
		<< "$(\"#sidebarBorder\").css(\"height\",heightSidebar);"
		<< "$(\"#sidebarBorder\").css(\"padding - top\",heightSidebar/2);"
		<< "$(\"#sidebarBorder\").click(onClickSidebarBorder);"

		/**
		This paragraph adds the title to the sidebar.
		Moreover the margin-left has to be defined so the title component doesn't overlaps with the sidebar border.
		*/

		<< "$(\"#sideBar\").append(\"<div id = 'sidebarTitle'class = 'SidebarTitle' style = 'height:\"+parseInt(heightSidebar/20)+\"px'>More Information</div>\");"
		//$("#sideBar").append("<input type='button' id='Btn1' value='Add Point' onclick='addPoint()' class='btnStyle span3' />");
		//$("#sideBar").append("<input type='button' id='Btn1' value='Save' onclick='' class='btnStyle span3' />");
		<< "$(\"#sidebarTitle\").css(\"margin - left\",$(\"#sidebarBorder\").width());"

		/**
		The element 'sidebarContent' contains the different information boxes.
		Moreover some attributes for design depending on other objects are defined.
		*/

		<< "$(\"#sideBar\").append(\"<div id = 'sidebarContent'class = 'SidebarContent'></div>\");"
		<< "$(\"#sidebarContent\").css(\"max - width\",parseInt(sidebar.getContainer().offsetWidth-parseInt($(\"#sidebarBorder\").width()))+\"px\");"
		<< "$(\"#sidebarContent\").css(\"margin - left\",$(\"#sidebarBorder\").width());"
		<< "$(\"#sidebarContent\").css(\"height\",parseInt(heightSidebar-(heightSidebar/20)-30)+\"px\");"
		/**
		Here some information boxes are created. The id for each element is defined.
		Moreover the minimum height for the boxes will be defined depending on the height of the sidebar.
		*/

		<< "for(var i=0;i<8;i++){"
		<< "$(\"#sidebarContent\").append(\"<div id = 'sidebarItem\"+i+\"'class = 'SidebarItem'>hello</div>\");"
		<< "$(\"#sidebarItem\"+i).css(\"max - width\",parseInt((sidebar.getContainer().offsetWidth)-parseInt($(\"#sidebarBorder\").width()))+\"px\");"
		<< "$(\"#sidebarItem\"+i).css(\"min - height\",parseInt(heightSidebar/6)+\"px\");"
		<< "}"

		//<!--map.on('click', onClickMap); (Used while testing.If one click on the map, the sidebar opens. -->
		<< " </script>"
		<< "</body>"
		<< "</html>";

	return 0;
}