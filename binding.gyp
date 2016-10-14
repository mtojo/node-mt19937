{
  "targets": [
    {
      "target_name": "mt19937",
      "cflags": [
        "-std=c++11",
        "-stdlib=libc++",
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
      ],
      "sources": [
        "src/mt19937.cpp",
      ],
      "xcode_settings": {
        "OTHER_CFLAGS": [
          "-std=c++11",
          "-stdlib=libc++",
        ],
      },
    },
  ],
}
