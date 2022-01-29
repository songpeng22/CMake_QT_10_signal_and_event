import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2

/**/
Window {
	id:idWindow1
	objectName: "objWindow1"
    visible: true
    width: 600
    height: 400
    title: qsTr("Hello World")

	Rectangle{
		id:idRect1
		objectName : "objRect1"
		color: "teal"
		height: idButton1.height
		anchors.left : parent.left
		anchors.right : parent.right

        signal send( string person, string notice)

        onSend: {
            console.log("For " + person + ", the notice is: " + notice);
        }

		Button {
			id: idButton1
			objectName: "objButton1"
			x: 0
			y: 0
			width: 173
			height: 88
			text: qsTr("txtButton1")
            onClicked: {
                data1.setData( 12 );
                //emit signal
                data1.dataChanged();
                //
                //idRect1.send("111","222");
                //idRect1.send.connect(sendToPost);
            }

		}

       Connections {
           target: data1
           onDataChanged: {
               idRect1.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
               data1.data();
           }
        }

        ComboBox {
            id: idComboBox1
            x: idButton1.width + 10
            width: 200
            //model 1
            model: [ "Banana", "Apple", "Coconut" ]
            //model 2
/*
            model: ListModel{
                id: cbItems
                ListElement{ text:"Banana"; color:"Yellow" }
                ListElement{ text:"Apple"; color:"Green" }
                ListElement{ text:"Plum"; color:"Plum" }
            }
*/
        }

        TextEdit{
            id: idTextEdit1
            objectName: "objTextEdit1"
            //anchors.left: idComboBox1.right
            width: 240
            text: "Hello World"
            font.family: "Helvetica"
            font.pointSize: 20
            color: "red"
            focus: true
        }

        function sendToPost(person, notice) {
            console.log("Sending to post: " + person + ", " + notice);
        }

        function sendToTelegraph(person, notice) {
            console.log("Sending to telegraph: " + person + ", " + notice)
        }

        function sendToEmail(person, notice) {
            console.log("Sending to email: " + person + ", " + notice)
        }
	}

}

