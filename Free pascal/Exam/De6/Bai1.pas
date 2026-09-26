Program bai1;
uses crt;
var n:integer;
procedure nhap(var n:integer);
 begin
   repeat
     write('-Nhap n: ');readln(n);
   until (n>0) and (n<10000);
 end;
function kt(n:integer):boolean;
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
  kt:=ok;
end;
procedure xuly(n:integer);
var i:integer;
begin
  writeln('- Cac so nguyen to: ');
  for i:=2 to n do
    if kt(i) then
      write(i,' ');
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.
