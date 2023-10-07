.read data.sql


CREATE TABLE average_prices AS
  SELECT category, AVG(MSRP) as average_price FROM products GROUP BY category;


CREATE TABLE lowest_prices AS
  SELECT store, item, MIN(price) FROM inventory GROUP BY item;


CREATE TABLE shopping_list AS
  SELECT item, store FROM lowest_prices, products
  WHERE item = name GROUP BY category HAVING MIN(MSRP / rating);


CREATE TABLE total_bandwidth AS
  SELECT SUM(Mbs) FROM shopping_list AS a, stores AS b WHERE a.store = b.store;

