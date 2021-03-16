CREATE VIEW [buecher 2007] AS
SELECT `titel`, `erschjahr`, `isbn`
FROM buch
WHERE erschjahr = "2007"
