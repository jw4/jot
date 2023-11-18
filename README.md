# jot

Helper utility to open a (possibly new) file in $EDITOR.

The default will be to open a file named with todays date: `<YYYY-MM-DD>.md`, but there
are several configuration options, to use date, time, or an iso-8601 format datetime.

Suffixes, prefixes, and root directories are also configurable.

## Config

The following environment variables can be used to override the defaults, and there
are command line flags that override the environment variables:

### Environment Variables

#### `EDITOR`

Setting `EDITOR` (`export EDITOR=vim` for example), will specify which command will be used to open the file.

The command line flag `-e <editor>` will override the environment.

#### `JOT_PREFIX`

Setting `JOT_PREFIX` will prepend the value to the generated base file name.

The flag `-p <prefix>` overrides the environment variable.

#### `JOT_SUFFIX`

Setting `JOT_PREFIX` will change the default `.md` to whatever is specified.
Any leading `.` will be stripped, and the final value of the prefix will be appended after the base file name as dot extension.

The flag `-s <suffix>` overrides the env.

#### `JOT_ROOT`

`JOT_ROOT` can be set to specify a root directory for the file, overriding the default of the current working directory.
No path validation is performed, so if it doesn't exist, or is invalid the results are undetermined.

The flag `-r <root>` overrides the env.

### Command line flags

#### `-d` (default)

Specifies the root filename pattern as an ISO date: `<YYYY-MM-DD>`

#### `-t`

Specifies the root filename pattern as a time: `<HH:mm:ss>`

#### `-i`

Specifies the root filename pattern as an ISO 8601 date time: `<YYYY-MM-DDTHH:mm:ss+00:00>`

#### `-e <editor>`

Specifies which program to use to open the generated filename.
See `$EDITOR`.

#### `-p <prefix>`

Specifies a prefix value for the filename.
See `$JOT_PREFIX`.

#### `-s <suffix>`

Specifies the file suffix value for the filename.
See `$JOT_SUFFIX`.

#### `-r <root>`

Specifies the root directory for the filename.
See `$JOT_ROOT`.
