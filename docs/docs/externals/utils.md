# Utility functions

## GetIntArrayValue

Returns value of index in the array of integers.

```dae
func int GetIntArrayValue(var string arr, var int index) {};
```

- `arr` - array of integers
- `index` - position of an element in an array
- `return` - value of index

```dae title="Example usage"
var int i; i = GetIntArrayValue(self.HitChance, NPC_TALENT_1H);
```

## GetStringArrayValue

Returns value of index in the array of strings.

```dae
func string GetStringArrayValue(var string arr, var int index) {};
```

- `arr` - array of strings
- `index` - position of an element in an array
- `return` - value of index

```dae title="Example usage"
var string str; str = GetStringArrayValue(TXT_GUILDS, GIL_VLK);
```

## SetIntArrayValue

```dae
func void SetIntArrayValue(var string arr, var int index, var int value) {};
```

- `arr` - array of integers
- `index` - position of an element in an array
- `value` - integer value to set

```dae title="Example usage"
SetIntArrayValue(self.HitChance, NPC_TALENT_1H, 25);
```

## SetStringArrayValue

```dae
func void SetStringArrayValue(var string arr, var int index, var string value) {};
```

- `arr` - array of strings
- `index` - position of an element in an array
- `value` - string value to set

```dae title="Example usage"
var string arr[2];
arr[0] = "Test";
arr[1] = "Test2";
SetStringArrayValue(arr, 1, "Test3");
```
