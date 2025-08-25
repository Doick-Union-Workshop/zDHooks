# String functions

## Str_Upper

Returns string with uppercase.

```dae
var string Str_Upper(var string str) {};
```

- `str` - string to format
- `return` - formatted string

```dae title="Example usage"
var string str; str = Str_Upper("Start");
Print(str); // START
```

## Str_Lower

Returns string with lowercase.

```dae
var string Str_Lower(var string str) {};
```

- `str` - string to format
- `return` - formatted string

```dae title="Example usage"
var string str; str = Str_Lower("Start");
Print(str); // start
```

## Str_Capitel

Returns string with capitelcase.

```dae
var string Str_Capitel(var string str) {};
```

- `str` - string to format
- `return` - formatted string

```dae title="Example usage"
var string str; str = Str_Capitel("start");
Print(str); // Start
```
