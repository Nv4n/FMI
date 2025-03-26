
new nothrow []...
Ако има памет за целия блок ще върне обекта и ако няма nullptr

прихващане на изключенията 

```cpp
try{
...
}
catch (std::bad_alloc &b){
    по-добре да бъде просто
    throw;
    вместо 
    throw b;
}
catch (char* n){

}
catch(std::Exception &e){

}
catch(...){

}

Данните трябва да се изчистят, винаги при проблем. Може да ликвидира нуждата от try+catch

delete a; - очаква един обект
delete[] a; - очавка масив

Копиране
array()
array(int)
array(int *)
```