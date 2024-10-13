/* Write your PL/SQL query statement below */
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p, Address a
WHERE p.personId = a.personId(+); 