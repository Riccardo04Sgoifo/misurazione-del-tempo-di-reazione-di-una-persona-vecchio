import QtQuick 2.15
import QtQuick.Controls.Material

SpinBox {

    textFromValue: function(value){
        return Number(value).toString();
    }
}
