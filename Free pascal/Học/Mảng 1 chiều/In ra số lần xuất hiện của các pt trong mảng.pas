Program pt_giong;
uses crt;
type manga=array[1..32000] of integer;
     mangb=array[1..32767] of integer;
var n:integer;
    a:manga;
procedure nhap(var a:manga; var n:integer);
var i:integer;
begin
  repeat
    write('Nhap so luong phan tu: ');readln(n);
  until (n>=1) and (n<=32000);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure inra(a:manga; n:integer);
var i,max:integer;
    b:mangb;
begin
  max:=a[1];
  for i:=2 to n do
    if max<a[i] then
      max:=a[i];
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    inc(b[a[i]]);
  for i:=1 to max do
    if b[i]<>0 then
      writeln(i,' xuat hien ',b[i],' lan');
end;
Begin
  clrscr;
  nhap(a,n);
  inra(a,n);
  readln
End.











