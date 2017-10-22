import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
        objectName: "category_tab"
        signal addCategorySignal(string category_name);
        x: 12;
        y: 12;

        CategoriesGrid {
                id: categories_grid
                width: parent.width / 3
                height: parent.height / 3
                anchors.topMargin: 1002
                anchors.top: parent.anchors.top
                anchors.leftMargin: 2000
                anchors.left: parent.anchors.left

                onCategoryClicked: {
                        console.log(categorie_id)
                }
        }

        TextInput {
                anchors.top: categories_grid.bottom
                width: parent.width / 10;
                height: parent.height / 10;
                anchors.topMargin: 12
                color: "#999"
                font.pointSize: 24
                id: category_name
        }

        Button {
                anchors.top: category_name.bottom
                onClicked: {
                        CategoryController.addCategory(category_name.text);
                        addCategorySignal(category_name.text)
                }

                style: ButtonStyle {
                        background: Rectangle {
                                color: "#999"
                        }

                        label: Text {
                                text: "Add category"
                                color: "#000"
                                font.bold: true
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                        }
                }
        }
}
