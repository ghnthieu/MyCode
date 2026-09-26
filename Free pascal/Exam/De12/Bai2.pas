Program So_Nguyen;
uses crt;
var n:integer;
procedure nhap(var n:integer);
begin
  readln(n);
end;
function shh(n:integer):boolean;
var i,tong:integer;
begin
  tong:=0;
  for i:=1 to n div 2 do
    if (n mod i=0) then
      tong:=tong+i;
  if (tong=n) then
    exit(true);
  exit(false);
end;
procedure xuly(n:integer);
var t,i:integer;
    s:string;
    ch:char;
    cs:byte;
begin
  t:=n;
  str(t,s);
  writeln('So ',n,' co ',length(s),' chu so');
  write('So hoan hao nho hon ',n,' la: ');
  for i:=1 to n do
    if (shh(i)) then
      write(i,' ');
  writeln;
  ch:='9';
  for i:=1 to length(s) do
    if ((s[i]<>'0') and (ord(s[i])<=ord(ch))) then
      begin
        ch:=s[i];
        cs:=i;
      end;
  delete(s,i,1);
  s:=ch+s;
  write('So sau khi bien doi la: ',s);
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.

