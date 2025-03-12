### getline(...) - чете от стандартния вход

- Ако не намира краен символ вдига fail()
- Ако достига края на потока и не намира символ за край вдига fail() и eof()

 file.gcount? казва колко символа има файла

'я' и EOF са един и същи символ за ASCII

write(file.get(ch))

## Бинарни файлове

```cpp
size_t size;
char memory [size];
file.read(memory,size);

file.write(memory, size)

cerr (по-бавен, но е сигурно, че това което трябва да получи грешката ще я получи)/clog (буферирен по-бърз)

file.flush()

ofstream file("data.txt",ios::out | ios::binary)
file.write((char const*)arr,50*sizeof arr[0])
file.flush()
if(file-binary???)

file.read((char *)arr,50 * sizeof(int))
if(file)...

--------------------

char* mem = (char *) arr;
size_t toRead= 50*sizeof(arr[0]);
while(file && toRead){
    file.read(mem,toRead);
    mem+=file.gcount();
    toRead -=file.gcount();
}

------------------------

struct Array{
    int size,
    int data[50],
} mat[5];

file.write ((const char*) mat, 5 * sizeof(*mat))


struct Array{
    int size,
    int* data,
} mat[5];

for (int i=0; i<5;i++){
    file.write(&mat[i].size, sizeof(int));
    file.write(&mat[i].data, mat[i].size * sizoef(int));

tellg (взима място при четене) / tellp (при писане)
seekg (променя място при четене) / seekp (при писане)

seek(offset), чисти .eof() и чисти буфери

seek(offset, direction) 
ios::beg
ios::end
ios::curr

------
Размер на файл - binary

file.clear();
file.seekg(0,ios::end);
size=file.tellg();
file.seekg(0);

file.seekg(file.tellg()); чисти буфери при бинарни файлове


```
