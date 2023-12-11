.read data.sql


CREATE TABLE average_prices AS
  SELECT category, avg(MSRP) as average_price
  FROM products
  group by category;


CREATE TABLE lowest_prices AS
  SELECT store, item, price
  FROM (SELECT * FROM inventory order by price)
  group by item;


CREATE TABLE shopping_list AS
  SELECT item, store
  FROM (SELECT b.item, b.store, a.category 
        FROM products as a, lowest_prices as b
        WHERE a.name = b.item
        order by a.MSRP / a.rating)
  group by category;

CREATE TABLE total_bandwidth AS
  SELECT SUM(b.Mbs)
  FROM shopping_list as a, stores as b
  WHERE a.store = b.store;

