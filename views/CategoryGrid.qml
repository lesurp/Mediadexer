import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4

Item {
    signal categoryClicked(int categoryId, string categoryName);
    GridView {
        id: grid
        width: parent.width;
        height: parent.height;
        clip:true;
        currentIndex: -1

        model: CategoryController.categories
        delegate: MyButton {
            width: grid.cellWidth;
            height: grid.cellHeight
            selected: GridView.isCurrentItem

            onClicked: {
                if(grid.currentIndex == index)
                    grid.currentIndex = -1;
                else
                    grid.currentIndex = index;
                categoryClicked(modelData.categoryId, modelData.categoryName);
            }

        }        }

    ScrollBar {
        flickable: grid
    }
}
