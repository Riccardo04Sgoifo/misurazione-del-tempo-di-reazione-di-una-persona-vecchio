import QtQuick
import QtQuick.Window
import QtQuick.Controls.Material
import QtQuick.Layouts
import QtQuick.Effects
import Basic

ApplicationWindow {
    width: 640
    height: 480
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    title: qsTr("Hello World")

    // style

    Material.theme: Material.Dark
    Material.roundedScale: Material.MediumScale

    font.pointSize: 12


    GridLayout {
        id: mainGrid
        rows: 2
        columns: 2
        anchors.fill: parent
        columnSpacing: 5
        anchors.margins: 5


        LightCanvas {
            id: canvas
            Layout.row: 0; Layout.column: 0
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Material.backgroundColor
        }


       ColumnLayout {
            id: controlPanel
            Layout.fillHeight: true
            Layout.maximumWidth: 400
            Layout.alignment: Qt.AlignTop
            Layout.margins: 5
            spacing: 5

            RowLayout {
                id: startPanel
                Layout.fillWidth: true
                Layout.fillHeight: true

                Button {
                    text: "Inizia"
                    onClicked: {
                        mainLogic.startAttempts();
                    }
                }

                SText {
                    text: "inizia tra:"

                }

                SSpinBox {
                    from: 0
                    to: 10000
                    value: mainLogic.startDelay
                    editable: true
                    stepSize: 100
                }

            }

            RowLayout {
                id: attemptsPanel
                Layout.fillWidth: true
                Layout.fillHeight: true

                SText {
                    text: "numero di tentativi:"
                }

                SSpinBox {
                    from: 1
                    to: 1000
                    value: mainLogic.attemptNum
                    editable: true
                    stepSize: 1

                }
            }

            RowLayout {
                id: timingModeBarNText
                Layout.preferredHeight: timingModeBar.implicitHeight
                Layout.fillWidth: true

                SText {
                    text: "intervallo:"
                }

                TabBar {
                    id: timingModeBar
                    Layout.fillWidth: true

                    TabButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "fisso"
                    }

                    TabButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "casuale"
                    }
                }
            }

            StackLayout {
                id: timingModePanels
                currentIndex: timingModeBar.currentIndex
                Layout.fillHeight: true
                Layout.fillWidth: true

                Item {
                    id: fixedModeTab
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    RowLayout {
                        anchors.fill: parent

                        SText {
                            text: "Intervallo di:"
                        }

                        SSpinBox {
                            from: 0
                            to: 10000
                            stepSize: 100
                        }
                    }
                }

                Item {
                    id: randomModeTab

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    ColumnLayout {
                        anchors.fill: parent

                        SText {
                            text: "Intervallo casuale da"
                        }

                        RowLayout {
                            Layout.fillWidth: true
                            Layout.fillHeight: true

                            SSpinBox {
                                from: 0
                                to: 10000
                                stepSize: 100
                            }

                            SText {
                                text: "a"
                            }

                            SSpinBox {
                                from: 0
                                to: 10000
                                stepSize: 100
                            }
                        }
                    }
                }
            }



        }

    }



}
