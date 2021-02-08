CREATE VIEW [ bücher von 2007] AS
SELECT titel, erschjahr, isbn
FROM buch
WHERE erschjahr = "2007";