USE [CSGO Matches]
GO

CREATE or ALTER PROCEDURE changeVersion(@TargetVersion INT)
AS
    DECLARE @current INT
    SELECT @current = [version] 
    FROM CrtVersion

    IF @TargetVersion > @current AND @TargetVersion <= 8 BEGIN
        DECLARE @NextVersion INT
        DECLARE @ProcedName VARCHAR(100)

        DECLARE VersionCursor CURSOR FOR
            SELECT uspUp, targetVersion
            FROM Procedures_versions
            ORDER BY targetVersion

        OPEN VersionCursor
        FETCH NEXT FROM VersionCursor
            INTO @ProcedName, @NextVersion

        WHILE @@FETCH_STATUS = 0 AND @NextVersion <= @TargetVersion BEGIN
            IF @NextVersion > @current BEGIN
                EXEC (@ProcedName)
            END
            FETCH NEXT FROM VersionCursor
                INTO @ProcedName, @NextVersion
        END

        UPDATE CrtVersion
        SET [version] = @TargetVersion
        WHERE [version] = @current

        CLOSE VersionCursor
        DEALLOCATE VersionCursor
    END

    ELSE IF @TargetVersion < @current AND  @TargetVersion >= 0 BEGIN

        DECLARE @PrevVersion INT
        DECLARE @ProcedName2 VARCHAR(100)

        DECLARE VersionCursor CURSOR FOR
            SELECT uspDown, newVersion = targetVersion - 1
            FROM Procedures_versions
            ORDER BY targetVersion DESC

        OPEN VersionCursor
        FETCH NEXT FROM VersionCursor
            INTO @ProcedName2, @PrevVersion

        WHILE @@FETCH_STATUS = 0 AND @PrevVersion >= @TargetVersion BEGIN

            IF @PrevVersion < @current BEGIN
                EXEC (@ProcedName2)
            END
                FETCH NEXT FROM VersionCursor
                    INTO @ProcedName2, @PrevVersion
        END

        UPDATE CrtVersion
        SET [version] = @TargetVersion
        WHERE [version] = @current

        CLOSE VersionCursor
        DEALLOCATE VersionCursor
    END
GO

/* ````````````````````````````````` */
/* The problem was with the order by in the @target < @current if 
It ordered them in ascending order and that's why it didn't work. */

EXEC changeVersion 0

SELECT * FROM CrtVersion
SELECT * FROM Procedures_versions

SELECT * FROM Fans
SELECT * FROM Fanbase