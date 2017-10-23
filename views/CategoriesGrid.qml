import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4

import mediadexer.Category 1.0

Item {
        signal categoryClicked(Category category);
        GridView {
                id: grid
                width: parent.width;
                height: parent.height;
                clip:true;
                currentIndex: -1

                model: CategoryController.categories
                delegate: Component {
                        Rectangle {
                                width: grid.cellWidth;
                                height: grid.cellHeight
                                color: GridView.isCurrentItem ? "green" : "#999"
                                Text {
                                        width: grid.cellWidth
                                        height: grid.cellHeight
                                        text: modelData.categoryName
                                        color: "#000"
                                        font.bold: true
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                        wrapMode: Text.Wrap;
                                }

                                MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                                if(grid.currentIndex == index)
                                                    grid.currentIndex = -1;
                                                else
                                                    grid.currentIndex = index;
                                                categoryClicked(modelData);
                                        }
                                }
                        }
                }
        }

        ScrollBar {
                flickable: grid
        }

}
