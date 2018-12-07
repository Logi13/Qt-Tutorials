import QtQuick 2.9
import QtQuick.LocalStorage 2.0
Item {
        // reference to the database object
    property var db;
    function initDatabase() {
        // initialize the database object
        print('initDatabase()')
        db = LocalStorage.openDatabaseSync("CrazyBox", "1.0", "A box who remembers it's position", 100000);
        db.transaction( function(tx) {
        print('... create table')
        tx.executeSql('CREATE TABLE IF NOT EXISTS data(name TEXT, value TEXT)');
        });
    }
    function storeData() {
        // stores data to DB
        print('storeData()')
        if(!db) { return; }
        db.transaction( function(fx){
            print('... check if a crazy object exists')
            var result = tx.executeSql('SELECT * from data where name = "crazy"');
            //prepare object to be stored as JSON
            var obj = { x: crazy.x, y:crazy.y };
            if(result.rows.length === 1){//use update
               print('... crazy exists, update it')
                result = tx.executeSql('UPDATE data set value=? where name="crazy"', [JSON.stringify(obj)]);
            } else { //use insert
                print('... crazy does not exist, create it')
                result = tx.executeSql('INSERT INTO data VALUES (?,?)', ['crazy', JSON.stringify(obj)]);
            }

        })
    }
    function readData() {
        // reads and applies data from DB
        print("readData()")
        if(!db) { return; }
        db.transaction( function(tx) {
            print('... rea crazy object')
            var result = tx.executeSql('select * from data where name = "crazy"');
            if(result.rows.length === 1) {
                print('... update crazy geometry')
                // get the value column
                var value = result.rows[0].value;
                //convert to JS object
                var obj = Json.parse(value)
                //apply to object
                crazy.x = obj.x;
                crazy.y = obj.y;
            }
        });
    }
    Component.onCompleted: {
        initDatabase();
        readData();
    }
    Component.onDestruction: {
        storeData();
    }
}

