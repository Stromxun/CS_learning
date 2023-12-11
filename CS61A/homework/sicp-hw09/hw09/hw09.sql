CREATE TABLE parents AS
  SELECT "abraham" AS parent, "barack" AS child UNION
  SELECT "abraham"          , "clinton"         UNION
  SELECT "delano"           , "herbert"         UNION
  SELECT "fillmore"         , "abraham"         UNION
  SELECT "fillmore"         , "delano"          UNION
  SELECT "fillmore"         , "grover"          UNION
  SELECT "eisenhower"       , "fillmore";

CREATE TABLE dogs AS
  SELECT "abraham" AS name, "long" AS fur, 26 AS height UNION
  SELECT "barack"         , "short"      , 52           UNION
  SELECT "clinton"        , "long"       , 47           UNION
  SELECT "delano"         , "long"       , 46           UNION
  SELECT "eisenhower"     , "short"      , 35           UNION
  SELECT "fillmore"       , "curly"      , 32           UNION
  SELECT "grover"         , "short"      , 28           UNION
  SELECT "herbert"        , "curly"      , 31;

CREATE TABLE sizes AS
  SELECT "toy" AS size, 24 AS min, 28 AS max UNION
  SELECT "mini"       , 28       , 35        UNION
  SELECT "medium"     , 35       , 45        UNION
  SELECT "standard"   , 45       , 60;


-- The size of each dog
CREATE TABLE size_of_dogs AS
  SELECT a.name, b.size as size
  FROM dogs as a, sizes as b
  WHERE  b.min < a.height and a.height <= b.max;


-- All dogs with parents ordered by decreasing height of their parent
CREATE TABLE by_parent_height AS
  SELECT a.child 
  FROM parents as a, dogs as b
  WHERE a.parent = b.name
  order by b.height DESC;



-- Filling out this helper table is optional
CREATE TABLE siblings AS
  SELECT a.child as bro1, b.child as bro2, c.size as similar_size
  FROM parents as a, parents as b, size_of_dogs as c, size_of_dogs as d
  WHERE c.name < d.name and a.parent = b.parent and c.name = a.child and d.name = b.child and c.size = d.size
  order by a.child;


-- Sentences about siblings that are the same size
CREATE TABLE sentences AS
  SELECT 'The two siblings, '|| bro1 ||' plus '|| bro2 || ' have the same size: '|| similar_size
  FROM siblings;

