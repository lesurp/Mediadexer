import QtQuick 2.0
import QtQuick.Controls 2.2

import mediadexer.searchnode 1.0

Item {
    signal categoryClicked(int categoryId, string categoryName);
    signal operatorButtonClicked(int op);
    objectName: "searchTab"
    CategoryGrid {
        id: categoryGrid
        width: parent.width / 3
        height: parent.height / 3

        onCategoryClicked: parent.categoryClicked(categoryId, categoryName);
    }


    Rectangle {
        color: '#333'
        id: queryText
        anchors.top: categoryGrid.bottom
        Text {
            width: parent.width
            height: parent.height
            text: SearchController.searchQuery;
        }
    }

    Row {
        anchors.top: queryText.bottom
        Button {
            text: "ADD"
            onClicked: operatorButtonClicked(SearchNode.Add);
        }
    }
}
