
SELECT NAME
FROM  PEOPLE
INNER JOIN DIRECTORS, RATINGS ON Directors.Movie_id = RATINGS.Movie_id  and Directors.person_id = PEOPLE.id
WHERE Rating>=9.0;
