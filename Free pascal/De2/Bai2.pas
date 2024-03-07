Program bai2;
uses crt;
var a,b:integer;
procedure nhap(var a,b:integer);
begin
  repeat
    readln(a,b);
  until (a>=1) and (b>=1) and (a<=5000) and (b<=5000);
end;
function ucln(a,b:integer):integer;
var sodu:integer;
begin
  sodu:=a mod b;
  while sodu<>0 do
    begin
      a:=b;
      b:=sodu;
      sodu:=a mod b;
    end;
  ucln:=b;
end;
procedure xuly(a,b:integer);
var i,x,y:integer;
begin
  writeln(a*b div ucln(a,b));
  x:=a div ucln(a,b);
  y:=b div ucln(a,b);
  write(x,' ',y);
end;
Begin
  clrscr;
  nhap(a,b);
  xuly(a,b);
  readln
End.
