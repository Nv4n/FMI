SET SCHEMA DB2SAMPLE;

CREATE TABLE CUSTOMERS
(CUSTNO   INTEGER NOT NULL PRIMARY KEY,
 STATUS   CHAR(1),
 XMLCUST  XML);

INSERT INTO CUSTOMERS (CUSTNO, STATUS, XMLCUST)
VALUES (120, '1',
'<customer>
    <custname>
        <first_name>Crag</first_name>
        <last_name>Muls</last_name>
    </custname>
    <addr country="US">
        <street>100 Easy St</street>
        <city>Pittsburgh</city>
        <state>PA</state>
        <zip_code>15215</zip_code>
      </addr>
    <phone type="work">412-555-1000</phone>
   <phone type="mobile">972-555-8174</phone>
</customer>'
);

SELECT * FROM CUSTOMERS;

select * from customers
where xmlexists('$XMLCUST/customer/addr[@country="US"]');

select custno, status, xmlquery('$XMLCUST/customer/custname') as cnames
from customers
where status = '1';

SELECT custno, xmlquery ('for $c in $XMLCUST/customer return $c')
FROM customers
WHERE status = '0';

xquery
for $i in
 db2-fn:xmlcolumn('CUSTOMERS.XMLCUST')/customer
let $cust := $i/custname
where $i/addr/@country = 'BG' or $i/addr/@country = 'RU'
order by $i/addr/@country
return
 <cust>
 {$i/addr/@country, $cust }
 </cust>