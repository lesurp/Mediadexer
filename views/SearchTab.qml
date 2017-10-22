import QtQuick 2.0
import QtQuick.Controls 2.2

Item {

    CategoriesGrid {
        width: parent.width / 3
        height: parent.height / 3

        onCategoryClicked: {
            console.log(categorie_id)
        }
    }


}
