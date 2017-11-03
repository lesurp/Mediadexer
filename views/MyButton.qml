import QtQuick 2.0

Rectangle {
    signal clicked;
    property alias text: buttonText.text;
    property bool selected: false;
    color: selected ? "green" : "#999"

    Text {
        id: buttonText
        width: parent.width;
        height: parent.height;
        text: modelData.categoryName
        color: "#000"
        font.bold: true
        wrapMode: Text.Wrap;
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked();
    }
}
