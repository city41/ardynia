import React from "react";
import classnames from "classnames";
import PropTypes from "prop-types";
import Helmet from "react-helmet";
import { StaticQuery, graphql } from "gatsby";

import Header from "./header";
import "./layout.css";
const titleImageUrl = "http://www.ardynia.com/title.png";

const Layout = ({ className, children }) => {
    const classes = classnames("layout", className);
    return (
        <StaticQuery
            query={graphql`
                query SiteTitleQuery {
                    site {
                        siteMetadata {
                            title
                            keywords
                            description
                            twitterHandle
                        }
                    }
                }
            `}
            render={data => (
                <>
                    <Helmet
                        title={data.site.siteMetadata.title}
                        meta={[
                            {
                                name: "description",
                                content: data.site.siteMetadata.title
                            },
                            {
                                name: "keywords",
                                content: data.site.siteMetadata.keywords
                            },
                            {
                                name: "twitter:card",
                                content: "summary"
                            },
                            {
                                name: "twitter:site",
                                content: data.site.siteMetadata.twitterHandle
                            },
                            {
                                name: "twitter:title",
                                content: data.site.siteMetadata.title
                            },
                            {
                                name: "twitter:description",
                                content: data.site.siteMetadata.description
                            },
                            {
                                name: "twitter:image",
                                content: titleImageUrl
                            },
                            {
                                name: "og:title",
                                content: data.site.siteMetadata.title
                            },
                            {
                                name: "og:type",
                                content: "website"
                            },
                            {
                                name: "og:url",
                                content: "http://www.ardynia.com"
                            },
                            {
                                name: "og:description",
                                content: data.site.siteMetadata.description
                            },
                            {
                                name: "og:image",
                                content: titleImageUrl
                            },
                            {
                                name: "og:title",
                                content: data.site.siteMetadata.title
                            }
                        ]}
                    >
                        <html lang="en" />
                    </Helmet>
                    <Header siteTitle={data.site.siteMetadata.title} />
                    <div className="layoutContainer">
                        <div className={classes}>{children}</div>
                    </div>
                </>
            )}
        />
    );
};

Layout.propTypes = {
    children: PropTypes.node.isRequired
};

export default Layout;
