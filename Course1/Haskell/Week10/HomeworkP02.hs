import Graphics.Win32.Misc (messageBeep)
main::IO()
main = do
    print $ actorsNetworthHigherThan 124000000 db -- → [([["Billy Bob Thornton","Scarlett Johansson"],["Kim Basinger","Alec Baldwin","Harrison Ford"],["Harrison Ford"]],["The Man Who Wasn't There","Star Wars","Empire Strikes Back"],"George Lucas",200000000),([["Liv Tyler"]],["Logan's run"],"Ted Turner",125000000)]
    print $ actorsNetworthHigherThan 125000000 db -- → [([["Billy Bob Thornton","Scarlett Johansson"],["Kim Basinger","Alec Baldwin","Harrison Ford"],["Harrison Ford"]],["The Man Who Wasn't There","Star Wars","Empire Strikes Back"],"George Lucas",200000000)]

--Movies:: (Title, Year, Length, ProducerName, ProducerID)
--Stars:: (Name, Gender)
--StarsIn:: (Star_Name, Movie_Name)
--Studios:: (StudioName, ProducerID)
--MovieExecs:: (ProducerName, ProducerID, Networth)
--DB:: movies, stars, starsIn, studios, movieExecs
--Networth -> DB -> [([[Stars_Name]],[Movies_Name], ProducerName, networth)]
actorsNetworthHigherThan :: Integer -> MovieDB -> [([[Name]], [Title], Name, Integer)]
actorsNetworthHigherThan num (ms,ss,sIs,sts,mEs) = helper getAllIds
    where
        helper:: [ProducerID] -> [([[Name]], [Title], Name, Integer)]
        helper [] = []
        helper (i:is) = (getAllActors $ getAllMovies i,getAllMovies i,getProducer i, getNetworth i) : helper is

        getProducer::ProducerID -> Name
        getProducer inpId = head $ map (\ (name,_,_) -> name) $ filter (\(_,id,_)->id==inpId) mEs

        getNetworth::ProducerID -> Networth
        getNetworth inpId = head $ map (\ (_,_,net) -> net) $ filter (\(_,id,_)->id==inpId) mEs

        getAllIds:: [ProducerID]
        getAllIds = [id | (name, id , net) <- mEs, net > num]

        getAllMovies:: ProducerID -> [Title]
        getAllMovies prodId = map (\ (title, _, _, _, _) -> title) $ filter (\ ( _, _, _, _, id) -> id == prodId) ms

        getActorsPerMovie:: Title -> [Name]
        getActorsPerMovie movieTitle = map fst $ filter (\ ( _, title) -> title == movieTitle) sIs

        getAllActors:: [Title] -> [[Name]]
        getAllActors [] = []
        getAllActors (t:ts) = getActorsPerMovie t : getAllActors ts


studios :: [Studio]
studios = [("Disney", 199),("USA Entertainm.", 222),("Fox",333),("Paramount", 123),("MGM", 555)]

movieExecs :: [MovieExec]
movieExecs = [("George Lucas", 555, 200000000),("Ted Turner",333, 125000000),("Stephen Spielberg", 222, 100000000),("Merv Griffin", 199, 112000000),("Calvin Coolidge", 123, 20000000)]

movies :: [Movie]
movies = [("Pretty Woman", 1990, 119, "Disney", 199),("The Man Who Wasn't There", 2001, 116, "USA Entertainm.",555),("Logan's run", 1976, 120, "Fox", 333),("Star Wars",1977, 124, "Fox", 555),("Empire Strikes Back", 1980, 111,"Fox", 555),("Star Trek", 1979, 132, "Paramount", 222),("Star Trek: Nemesis", 2002, 116, "Paramount", 123),("Terms of Endearment", 1983, 132, "MGM", 123),("The Usual Suspects",1995, 106, "MGM", 199),("Gone With the Wind", 1938, 238,"MGM", 123),("The Fellowship of the Ring", 2001, 178, "USA Entertainm.", 222)]
stars :: [MovieStar]
stars = [("Jane Fonda", 'F'),("Alec Baldwin", 'M'),("Kim Basinger", 'F'),("Harrison Ford", 'M'),("Debra Winger",'F'),("Jack Nicholson", 'M'),("Sandra Bullock", 'F'),("Orlando Bloom", 'M'),("Cate Blanchett", 'F'),("Liv Tyler",'F'),("Billy Bob Thornton", 'M'),("Scarlett Johansson", 'F')]

starsIn :: [StarsIn]
starsIn = [("Kim Basinger", "Star Wars"),("Alec Baldwin","Star Wars"),("Harrison Ford", "Star Wars"),("Harrison Ford","Empire Strikes Back"),("Jack Nicholson", "The Usual Suspects"),("Jane Fonda", "Terms of Endearment"),("Jack Nicholson", "Terms of Endearment"),("Sandra Bulloc", "The Usual Suspects"),("Billy Bob Thornton", "The Man Who Wasn't There"),("Scarlett Johansson", "The Man Who Wasn't There"),("Orlando Bloom", "The Fellowship of the Ring"),("Cate Blanchett", "The Fellowship of the Ring"),("Liv Tyler", "Logan's run")]

db :: MovieDB
db = (movies, stars, starsIn, studios, movieExecs)

type Name = String
type Title = String
type Address = String
type Year = Int
type Gender = Char
type Length = Int
type ProducerID = Int
type Networth = Integer
type Movie = (Title, Year, Length, Name, ProducerID)
type MovieStar = (Name, Gender)
type StarsIn = (Name, Title)
type Studio = (Name, Int)
type MovieExec = (Name, ProducerID, Networth)
type MovieDB = ([Movie], [MovieStar], [StarsIn], [Studio],[MovieExec])
