Uses crt;
type manga=array[1..100] of integer;
     mangb=array[1..32767] of integer;
var a:manga;
    n:byte;
procedure nhap(var a:manga; var n:byte);
var i:byte;
begin
  write('Nhap do dai mang: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure inra(a:manga; n:byte);
var max_a,i,max_b:integer;
    b:mangb;
begin
  max_a:=a[1];
  for i:=2 to n do
    if max_a<a[i] then
      max_a:=a[i];
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    inc(b[a[i]]);
  max_b:=b[1];
  for i:=2 to max_a do
    if max_b<b[i] then
      max_b:=b[i];
  if max_b=1 then
    writeln('Khong co phan tu trung nhau')
  else
    for i:=1 to max_a do
      if b[i]=max_b then
        writeln('Phan tu chinh la: ',i,':',b[i],' lan');
end;
Begin
  clrscr;
  nhap(a,n);
  inra(a,n);
  readln
End.





