SELECT DISTINCT NAME
FROM  PEOPLE
INNER JOIN STARS, MOVIES ON STARS.Movie_id = Movies.ID  and STARS.person_id = PEOPLE.id
WHERE YEAR=2004
ORDER BY BIRTH;