const db = require("../database");

const card = {
    getAllCards: function(callback) {
        return db.query("SELECT * FROM card",callback);
    },
    getOneCard: function(id, callback) {
        return db.query("SELECT * FROM card WHERE id_card=?",[id],callback);
    },
    addCard: function(newData, callback) {
        return db.query("INSERT INTO card(type,pin,id_user,attempts) VALUES(?,?,?,?)",
        [newData.type,newData.pin,newData.id_user,newData.attempts],
        callback);
    },
    updateCard: function(id, newData, callback) {
        return db.query("UPDATE card SET type=?,pin=?,id_user=?,attempts=? WHERE id_card=?",
        [newData.type,newData.pin,newData.id_user,newData.attempts],
        callback);
    },
    deleteCard: function(id, callback) {
        return db.query("DELETE FROM card WHERE id_card=?",[id],callback);
    }


};

module.exports = card;