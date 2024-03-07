Program bai3;
uses crt;
var m,n:integer;
procedure nhap(var m,n:integer);
begin
  repeat
    write('Nhap m: ');readln(m);
  until (m>0) and (m<32767);
  repeat
    write('Nhap n: ');readln(n);
  until (n>0) and (n<32767);
end;
function ucln(m,n:integer):integer;
var sodu:integer;
begin
  sodu:=m mod n;
  while sodu<>0 do
    begin
      m:=n;
      n:=sodu;
      sodu:=m mod n;
    end;
  ucln:=n;
end;
procedure xuly(m,n:integer);
begin
  write('BCNN(',m,',',n,')=',(m*n div ucln(m,n)));
end;
Begin
  clrscr;
  nhap(m,n);
  xuly(m,n);
  readln
End.
