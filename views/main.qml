import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    visible: true
    objectName: "asd"
    width: 1280
    height: 900

    TabView {
            objectName: "tab_view"
            anchors.fill: parent
            anchors.margins: 4
            Tab {
                    title: "SEARCH"
                    SearchTab {

                    }
            }
            Tab { title: "BROWSE" }
            Tab { title: "CATEGORIES"
                    CategoriesTab {}
            }
            Tab { title: "SETTINGS"
                    SearchTab {

                    }
            }

            style: TabViewStyle {
                    frameOverlap: 1
                    tab: Rectangle {
                            color: styleData.selected ? "#333" :"#999"
                            border.color:  "#333"
                            implicitWidth: Math.max(text.width + 4, 80)
                            implicitHeight: 20
                            radius: 2
                            Text {
                                    id: text
                                    anchors.centerIn: parent
                                    text: styleData.title
                                    color: styleData.selected ? "#0b0" : "#333"
                                    font.bold: true
                            }
                    }
                    frame: Rectangle { color: "#333" }
            }
    }
}
