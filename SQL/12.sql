
SELECT TITLE
FROM  MOVIES
INNER JOIN STARS, PEOPLE ON STARS.Movie_id = MOVIES.id and STARS.person_id = PEOPLE.id AND PEOPLE.name="Johnny Depp" 
wHERE title in (
SELECT TITLE
FROM  MOVIES
INNER JOIN STARS, PEOPLE ON STARS.Movie_id = MOVIES.id and STARS.person_id = PEOPLE.id AND PEOPLE.name="Helena Bonham Carter" )
;
