import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
        objectName: "categoryTab"
        signal addCategory(string categoryName);
        signal updateCategory(int categoryId, string categoryName);
        signal deleteCategory(int categoryId);
        property int selectedCategoryId: -1;
        x: 12;
        y: 12;

        CategoriesGrid {
                id: categories_grid
                width: parent.width / 3
                height: parent.height / 3

                onCategoryClicked: {
                        if(categoryId === selectedCategoryId) {
                                selectedCategoryId = -1;
                                category_text_input.text = ""
                                update_add_button_text.text = "Add category"
                                delete_button.visible = false;
                        } else {
                                selectedCategoryId = categoryId;
                                category_text_input.text = categoryName;
                                update_add_button_text.text = "Update category: " + categoryName;
                                delete_button.visible = true;
                        }
                }
        }

        TextInput {
                id: category_text_input
                anchors.top: categories_grid.bottom
                width: parent.width / 10;
                height: parent.height / 10;
                anchors.topMargin: 12
                color: "#999"
                font.pointSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                maximumLength: 32;
        }

        Rectangle {
                anchors.top: category_text_input.bottom
                id: update_add_button
                color: "#999"
                width: parent.width / 5;
                height: parent.height / 20;

                MouseArea{
                        anchors.fill: parent;
                        onClicked: {
                            if(selectedCategoryId === -1) {
                                addCategory(category_text_input.text);
                                category_text_input.text = "";
                                category_text_input.focus = false;
                            }
                            else {
                                updateCategory(selectedCategoryId, category_text_input.text);
                            }
                        }
                }

                Text {
                        id: update_add_button_text
                        width: parent.width;
                        height: parent.height;
                        text: "Add category"
                        color: "#000"
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                }
        }

        Rectangle {
                anchors.top: update_add_button.bottom
                anchors.topMargin: 12
                id: delete_button
                color: "#999"
                width: parent.width / 5;
                height: parent.height / 20;
                visible: false;

                MouseArea{
                        anchors.fill: parent;
                        onClicked: {
                                deleteCategory(selectedCategoryId);
                        }
                }

                Text {
                        width: parent.width;
                        height: parent.height;
                        text: "Delete selected category"
                        color: "#000"
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                }
        }

}
