module.exports = {
    siteMetadata: {
        title: "Ardynia",
        keywords: "Arduboy, game, zelda style, adventure",
        description: "An adventure game for the Arduboy in the style of Zelda",
        twitterHandle: "@mattegreer"
    },
    plugins: [
        "gatsby-plugin-react-helmet",
        {
            resolve: `gatsby-plugin-manifest`,
            options: {
                name: "Ardynia for Arduboy",
                short_name: "Ardynia",
                start_url: "/",
                background_color: "#663399",
                theme_color: "#663399",
                display: "minimal-ui",
                icon: "src/images/keyForFavicon.png" // This path is relative to the root of the site.
            }
        },
        "gatsby-plugin-offline",
        {
            resolve: "gatsby-plugin-favicon",
            options: {
                logo: "./src/images/keyForFavicon.png",

                // WebApp Manifest Configuration
                appName: null, // Inferred with your package.json
                appDescription: null,
                developerName: null,
                developerURL: null,
                dir: "auto",
                lang: "en-US",
                background: "#fff",
                theme_color: "#fff",
                display: "standalone",
                orientation: "any",
                start_url: "/?homescreen=1",
                version: "1.0",

                icons: {
                    android: true,
                    appleIcon: true,
                    appleStartup: true,
                    coast: false,
                    favicons: true,
                    firefox: true,
                    opengraph: false,
                    twitter: false,
                    yandex: false,
                    windows: false
                }
            }
        }
    ]
};
