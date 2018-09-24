program x_times_y;

var x: integer;
var y: integer;
var i: integer;
var j: integer;

begin
x:=5;
y:=3;
i:=0;
j:=0;

	while i <> x do begin
		j:= j+y;
		i:=i + 1;
	end;
	writeln(j);
end.
