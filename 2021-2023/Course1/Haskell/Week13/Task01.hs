import Data.List
main::IO()
main = do
    print $ rf (Song "Mozart""The Marriage of Figaro Overture" 270) -- ➝ "Summertime"
    print $ rf (Song "Gershwin""Summertime" 300) -- ➝ "Rhapsody in Blue"
    print $ rf (Song "Gershwin""Rhapsody in Blue" 1100) -- ➝ "Rhapsody in Blue"


recommender :: Playlist -> (Song -> SongName)
recommender pls sng = recommendSong sng
    where
        recommendSong::Song -> SongName
        recommendSong song
            | nextSongName /= [] = head nextSongName
            | songList /= [] =  getSongName $ head songList
            | otherwise = getSongName song

        songList = getSongListAfterSong
        authorName = getAuthorName
        nextSongName = nextSongNameByAuthor

        nextSongNameByAuthor:: [SongName]
        nextSongNameByAuthor = map getSongName $ filter (\ (Song aut _ _) -> aut == authorName) songList

        getSongListAfterSong:: [Song]
        getSongListAfterSong = drop 1 $ dropWhile (/= sng) $ (\ (Playlist songs) ->songs ) pls


        getSongName :: Song -> SongName
        getSongName song = (\(Song _ songName _) -> songName ) song

        getAuthorName:: AuthorName
        getAuthorName  = (\ (Song aut _ _) -> aut ) sng


rf = recommender (Playlist songs)

songs = [Song "Mozart" "The Marriage of Figaro Overture" 270,Song "Gershwin" "Summertime" 300,Song "Queen" "Bohemian Rhapsody" 355,Song "Gershwin""Rhapsody in Blue" 1100]
type AuthorName = String
type SongName = String
type SongLength = Int
data Song = Song AuthorName SongName SongLength deriving (Eq)
data Playlist = Playlist [Song]
