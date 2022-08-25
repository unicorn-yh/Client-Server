-- Active: 1653881177471@@127.0.0.1@3306@im
CREATE TABLE user(  
    id int NOT NULL UNIQUE PRIMARY KEY AUTO_INCREMENT,  /*用户id：自动添加*/
    username  VARCHAR(25) NOT NULL UNIQUE,
    password VARCHAR(25) NOT NULL,
    photo BLOB,
    sex VARCHAR(2),
    phone VARCHAR(15),
    create_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP /*用户注册时间：自动添加*/
);

drop TABLE user;

select * from user;

INSERT INTO userdata(username,password,sex,phone_number,port) VALUES
("admin123","admin123", "男","18954532417",9999),
("admin456","admin456", "男","18954432417",9998),
("admin789","admin789", "男","18954532465",9997),
("jessica1","123456", "女","18954532416",9994),
("whoami2","123456", "男","18954532415",9993),
("ketty9998","123456", "女","18954532414",9992),
("user12345","123456", "男","18954532413",9991);

INSERT INTO friendlist(username,friendname,friendip,friendport) VALUES
("admin123","jessica1", "127.0.0.1",9994),
("admin123","admin456", "127.0.0.1",9998),
("admin456","admin123", "127.0.0.1",9998);


CREATE TABLE log( 
    id int NOT NULL PRIMARY KEY,
    ip VARCHAR(16),          
    port_no VARCHAR(16),     /*端口号*/
    device VARCHAR(35),      
    action VARCHAR(255),     /*行为：登录、注册、退出登录*/
    FOREIGN KEY(id) REFERENCES user(id) 
);

drop TABLE log;

CREATE TABLE friend(  
    id int NOT NULL,
    friend_id int NOT NULL,
    remark_name VARCHAR(15),     /*好友备注*/
    PRIMARY KEY(id,friend_id),
    FOREIGN KEY(id) REFERENCES user(id),
    FOREIGN KEY(friend_id) REFERENCES user(id)
);

drop TABLE friend;

CREATE TABLE blacklist(  
    id int NOT NULL,
    friend_id int NOT NULL,
    PRIMARY KEY(id,friend_id),
    FOREIGN KEY(id) REFERENCES user(id),
    FOREIGN KEY(friend_id) REFERENCES user(id)
);

drop TABLE blacklist;

CREATE TABLE personal_chat(  
    id int NOT NULL,
    friend_id int NOT NULL,
    chat VARCHAR(255),
    PRIMARY KEY(id,friend_id),
    FOREIGN KEY(id) REFERENCES user(id),
    FOREIGN KEY(friend_id) REFERENCES user(id)
);

drop TABLE personal_chat;

CREATE TABLE group_chat(  
    group_id int NOT NULL,
    group_name VARCHAR(25),
    chat VARCHAR(255),
    PRIMARY KEY(group_id)
);

drop TABLE group_chat;

CREATE TABLE group_user(  
    user_id int NOT NULL,
    group_id int,
    PRIMARY KEY(user_id,group_id),
    FOREIGN KEY(user_id) REFERENCES user(id),
    FOREIGN KEY(group_id) REFERENCES group_chat(group_id)
);

drop TABLE group_user;

CREATE TABLE file_transfer(
    id int NOT NULL,
    friend_id int NOT NULL,
    file BLOB,
    FOREIGN KEY(id) REFERENCES user(id),
    FOREIGN KEY(friend_id) REFERENCES user(id)
);

drop TABLE file_transfer;

INSERT INTO file_transfer 
VALUES(1, 2, LOAD_FILE('logo.png')); /*绝对路径*/

select * from file_transfer;

SHOW TABLES;













