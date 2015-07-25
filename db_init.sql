CREATE TABLE IF NOT EXISTS sensors (
    id SMALLINT UNSIGNED NOT NULL PRIMARY KEY,
    type CHAR(16) NOT NULL,
    location CHAR(32) NOT NULL,
    zone CHAR(32) NOT NULL,
    system CHAR(32) NOT NULL
);

CREATE TABLE IF NOT EXISTS measurements (
    id SMALLINT UNSIGNED NOT NULL PRIMARY KEY,
    datetime TIMESTAMP NOT NULL,
    sensor SMALLINT UNSIGNED NOT NULL,
    reading DECIMAL(7,3) NOT NULL
);
