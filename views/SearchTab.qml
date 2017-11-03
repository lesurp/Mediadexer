import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import mediadexer.searchnode 1.0

Item {
    signal categoryClicked(int categoryId, string categoryName);
    signal formatterClicked(int nodeType);
    objectName: "searchTab"
    CategoryGrid {
        id: categoryGrid
        width: parent.width / 3
        height: parent.height / 3

        onCategoryClicked: parent.categoryClicked(categoryId, categoryName);
    }


        Text {
        id: queryText
        anchors.top: categoryGrid.bottom
            color: "#999"
            width: parent.width
            text: SearchController.searchQuery;
    }

    GridLayout {
        columns: 4
        anchors.top: queryText.bottom
        MyButton {
            width: 50
            height: 30
            text: "+"
            onClicked: formatterClicked(SearchNode.Plus);
        }
        MyButton {
            width: 50
            height: 30
            text: "("
            onClicked: formatterClicked(SearchNode.OpenParen);
        }
        MyButton {
            width: 50
            height: 30
            text: "AND"
            onClicked: formatterClicked(SearchNode.And);
        }
        MyButton {
            width: 50
            height: 30
            text: "="
            onClicked: formatterClicked(SearchNode.Equal);
        }
        MyButton {
            width: 50
            height: 30
            text: "-"
            onClicked: formatterClicked(SearchNode.Minus);
        }
        MyButton {
            width: 50
            height: 30
            text: "OR"
            onClicked: formatterClicked(SearchNode.Or);
        }
        MyButton {
            width: 50
            height: 30
            text: ")"
            onClicked: formatterClicked(SearchNode.CloseParen);
        }
        MyButton {
            width: 50
            height: 30
            text: "≠"
            onClicked: formatterClicked(SearchNode.Different);
        }
    }
}
