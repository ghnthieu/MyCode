Program bai1;
uses crt;
var n:integer;
procedure nhap(var n:integer);
begin
  repeat
    readln(n);
  until (n>0) and (n<1000);
end;
function snt(n:integer):boolean;
var ok:boolean;
    i:integer;
begin
  ok:=true;
  if n<2 then
    ok:=false
  else
    for i:=2 to trunc(sqrt(n)) do
      if n mod i=0 then
        begin
          ok:=false;
          break;
        end;
  snt:=ok;
end;
procedure xuly(n:integer);
var i:integer;
begin
  write('-Cac uoc la: ');
  for i:=1 to n do
    if n mod i=0 then
      write(i,' ');
  writeln;
  write('-Cac uoc so nguyen to: ');
  for i:=1 to n do
    if (n mod i=0) and (snt(i)) then
      write(i,' ');
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.






