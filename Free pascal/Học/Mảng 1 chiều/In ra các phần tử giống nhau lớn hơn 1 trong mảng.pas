Uses crt;
type manga=array[0..32000] of integer;
     mangb=array[0..32767] of integer;
var a:manga;
    n:integer;
procedure nhap(var a:manga; var n:integer);
var i:integer;
begin
  repeat
    write('Nhap do dai mang: ');readln(n);
  until (n>=1) and (n<=32000);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure inra(a:manga; n:integer);
var i,max,dem:integer;
    b:mangb;
begin
  max:=a[1];
  for i:=2 to n do
    if max<a[i] then
      max:=a[i];
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    inc(b[a[i]]);
  dem:=0;
  for i:=1 to max do
    if b[i]>1 then
      begin
        writeln(i,' xuat hien ',b[i],' lan');
        inc(dem);
      end;
  if dem=0 then
    writeln('Khong co phan tu trung');
end;
Begin
  clrscr;
  nhap(a,n);
  inra(a,n);
  readln
End.