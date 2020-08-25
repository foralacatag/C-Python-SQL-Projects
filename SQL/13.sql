SELECT NAME
FROM  PEOPLE
INNER JOIN STARS  ON  STARS.person_id = PEOPLE.id  and PEOPLE.name <> "Kevin Bacon" 
wHERE STARS.Movie_id in (
SELECT Movie_id
FROM  STARS
INNER JOIN PEOPLE ON STARS.person_id = PEOPLE.id 
WHERE PEOPLE.name="Kevin Bacon" and PEOPLE.birth=1958)
;
