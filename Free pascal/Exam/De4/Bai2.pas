Program bai2;
uses crt;
var a,b:integer;
procedure nhap(var a,b:integer);
begin
  readln(a);
  readln(b);
end;
procedure xuly(a,b:integer);
var cv,dt:integer;
begin
  cv:=(a+b)*2;
  dt:=a*b;
  writeln('Chu vi: ',cv);
  writeln('Dien tich: ',dt);
end;
Begin
  clrscr;
  nhap(a,b);
  xuly(a,b);
  readln
End.
