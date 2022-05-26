import Data.List
main::IO()
main = do
    print $ rf (Song "Mozart""The Marriage of Figaro Overture" 270) -- ➝ "Summertime"
    print $ rf (Song "Gershwin""Summertime" 300) -- ➝ "Rhapsody in Blue"
    print $ rf (Song "Gershwin""Rhapsody in Blue" 1100) -- ➝ "Rhapsody in Blue"


recommender :: Playlist -> (Song -> SongName)
recommender pls = helper sng
    where
        helper::Song -> SongName
        helper song
            | rs == [] = song
            | otherwise = fst $ dropWhile (Song -> r) rs

        autName:: Song -> AuthorName
        authName song = map (Song aut _ _ _ -> aut) song

        rs::SongName
        rs = getNextSong $ song

        getNextSong::Song -> SongName
        getNextSong song = dropWhile (song != pl ->pl) pls

rf = recommender (Playlist songs)

songs = [(Song "Mozart" "The Marriage of Figaro Overture" 270),(Song "Gershwin" "Summertime" 300),(Song "Queen" "Bohemian Rhapsody" 355),(Song "Gershwin""Rhapsody in Blue" 1100)]
type AuthorName = String
type SongName = String
type SongLength = Int
data Song = Song AuthorName SongName SongLength deriving (Eq)
data Playlist = Playlist [Song]
