-- Active: 1653881177471@@127.0.0.1@3306@im
CREATE TABLE user(  
    id INTEGER NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
    username  VARCHAR(25) NOT NULL UNIQUE,
    password VARCHAR(25) NOT NULL,
    photo BLOB,
    sex VARCHAR(2),
    phone VARCHAR(15),
    create_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE log( 
    id INTEGER NOT NULL PRIMARY KEY,
    ip VARCHAR(16),          
    port_no VARCHAR(16),     /*端口号*/
    device VARCHAR(35),      
    action VARCHAR(255),     /*行为：登录、注册、退出登录*/
    location VARCHAR(35),
    log_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP, /*用户操作时间：自动添加*/
    FOREIGN KEY(id) REFERENCES user(id) 
);

CREATE TABLE friend(  
    id INTEGER NOT NULL,
    friend_id int NOT NULL,
    remark_name VARCHAR(15),     /*好友备注*/
    PRIMARY KEY(id,friend_id),
    FOREIGN KEY(id) REFERENCES user(id),
    FOREIGN KEY(friend_id) REFERENCES user(id)
);

CREATE TABLE blacklist(  
    id INTEGER NOT NULL,
    friend_id INTEGER NOT NULL,
    PRIMARY KEY(id,friend_id),
    FOREIGN KEY(id) REFERENCES user(id),
    FOREIGN KEY(friend_id) REFERENCES user(id)
);

CREATE TABLE personal_chat(  
    id INTEGER NOT NULL,
    friend_id INTEGER NOT NULL,
    chat VARCHAR(255),
    PRIMARY KEY(id,friend_id),
    FOREIGN KEY(id) REFERENCES user(id),
    FOREIGN KEY(friend_id) REFERENCES user(id)
);

CREATE TABLE file_transfer(
    id INTEGER NOT NULL,
    friend_id INTEGER NOT NULL,
    file BLOB,
    transfer_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP, /*文件传输时间：自动添加*/
    FOREIGN KEY(id) REFERENCES user(id),
    FOREIGN KEY(friend_id) REFERENCES user(id)
);

SHOW TABLES;













