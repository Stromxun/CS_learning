.read data.sql


CREATE TABLE bluedog AS
  SELECT color, pet FROM students WHERE color = 'blue' and pet = 'dog';

CREATE TABLE bluedog_songs AS
  SELECT color, pet, song FROM students WHERE color = 'blue' and pet = 'dog';


CREATE TABLE smallest_int AS
  SELECT time, smallest FROM students WHERE smallest > 2 order by smallest limit 20 ;


CREATE TABLE matchmaker AS
  SELECT a.pet, a.song, a.color, b.color
  FROM students as a, students as b
  WHERE a.time < b.time and (a.song = b.song and a.pet = b.pet);


CREATE TABLE sevens AS
  SELECT a.seven
  FROM students as a, numbers as b
  WHERE a.time = b.time and a.number = 7 and b.'7' = 'True';

