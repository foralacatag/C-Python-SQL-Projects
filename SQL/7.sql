
SELECT Movies.TITLE, Ratings.Rating
FROM  MOVIES
INNER JOIN RATINGS ON RATINGS.Movie_id = Movies.ID
WHERE Movies.year=2010
ORDER BY Ratings.Rating DESC, Movies.TITLE ASC ;
