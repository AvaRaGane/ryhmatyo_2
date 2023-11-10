const db = require("../database");

const card = {
    getAllCards: function(callback) {
        return db.query("SELECT * FROM card",callback);
    },
    getOneCard: function(id, callback) {
        return db.query("SELECT * FROM card WHERE id_card=?",[id],callback);
    },
    addCard: function(newData, callback) {
        return db.query("INSERT INTO card(id_card,type,pin,id_user,attempts) VALUES(?,?,?,?,?)",
        [newData.id_card,newData.bank_name,newData.account_type,newData.balance,newData.max_withdrawal_per_day,newData.credit_limit],
        callback);
    },
    updateAccount: function(id, newData, callback) {
        return db.query("UPDATE account SET account_nmbr=?,bank_name=?,account_type=?,balance=?,max_withdrawal_per_day=?,credit_limit=? WHERE id_account=?",
        [newData.account_nmbr,newData.bank_name,newData.account_type,newData.balance,newData.max_withdrawal_per_day,newData.credit_limit,id],
        callback);
    },
    deleteAccount: function(id, callback) {
        return db.query("DELETE FROM account WHERE id_account=?",[id],callback);
    }


};

module.exports = card;