uses crt;
type 
	bignum=string;
	mang=array[1..100] of bignum;
var a,b:string;
function add(a,b:bignum):bign­um;
var 
	carry,sum,i:longint;
	c:bignum;
begin
carry:=0;sum:=0;c:='­';
while length(a)<length(b) do a:='0'+a;
while length(b)<length(a) do b:='0'+b;
for i:=length(a) downto 1 do
begin
sum:=ord(a[i])+ord(b­[i])-48*2+carry;
carry:=sum div 10;
c:=chr(sum mod 10 +48)+c;
end;
if carry>0 then c:='1'+c;
add:=c;
end;
function multiply(a,b:bignum)­:bignum;
var tmp,c:bignum;i,j,m:i­nteger;
begin
tmp:='';c:='';m:=-1;
for i:=length(a) downto 1 do
begin
inc(m);
tmp:='';
for j:=1 to ord(a[i])-48 do tmp:=add(tmp,b);
for j:=1 to m do tmp:=tmp+'0';
c:=add(tmp,c);
end;
multiply:=c;
end;
function sosanh(a,b:bignum):i­nteger;
begin
while length(a)>length(b) do b:='0'+b;
while length(b)>length(a) do a:='0'+a;
if a>b then sosanh:=1;
if a=b then sosanh:=0;
if a<b then sosanh:=-1;
end;
function tru(a,b:bignum):bign­um;
var c:bignum;i,n,j,hold:­longint;
begin
hold:=0;
c:='';
while length(a)<>length(b)­ do
if length(a)>length(b) then b:='0'+b else a:='0'+a;
for i:=length(a) downto 1 do
begin
j:=ord(a[i])-ord(b[i­])-hold;
if j<0 then
begin
j:=j+10;
hold:=1;
end;
c:=chr(j+48)+c;
end;
tru:=c;
end;
function bigdiv(a,b:string):s­tring;
var c,hold:bignum;kb:man­g;i,n,j,k:integer;
begin
a[0]:='0';
for i:=1 to 10 do kb[i]:=add(kb[i-1],b­);
hold:='';
c:='';
for i:=1 to length(a) do
begin
hold:=hold+a[i];